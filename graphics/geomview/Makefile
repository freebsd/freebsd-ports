# New ports collection makefile for:	geomview
# Date created:				5 November 1996
# Whom:					fenner
#
# $FreeBSD$
#

PORTNAME=	geomview
PORTVERSION=	1.9.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive viewer for 3- and 4-D geometric objects

NOT_FOR_ARCHS=	amd64
NOT_FOR_ARCHS_REASON=	Segfaults on amd64

OPTIONS=	MOTION_AVG "Use experimental motion averaging code" off

USE_BZIP2=	yes
USE_MOTIF=	yes
USE_GL=		glu
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-motif=${LOCALBASE} --with-opengl=${LOCALBASE}
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		animate.1gv anytooff.1gv anytoucd.1gv bdy.1gv bez2mesh.1gv \
		clip.1gv geomview.1gv hvectext.1gv math2oogl.1gv nose.1gv \
		offconsol.1gv oogl2rib.1gv oogl2vrml.1gv polymerge.1gv \
		togeomview.1gv ucdtooff.1gv vrml2oogl.1gv
MAN3=		anytopl.3gv bdy.3gv fsaparse.3gv geomutil.3gv lisp.3gv \
		plcombine.3gv plconsol.3gv
MAN5=		discgrp.5gv geomview.5gv oogl.5gv
INFO=		geomview

# Set "CPU" type for Geomview make
# Allow user to specify "make install MAPLE_LIB=foo" as geomview wants
MAKE_ENV=	CPU=FreeBSD MAPLE_LIB=${MAPLE_LIB}

.include <bsd.port.pre.mk>

.if defined(WITH_MOTION_AVG)
CONFIGURE_ARGS+=	--enable-motion-averaging
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|doc||g' ${WRKSRC}/Makefile.in
.for i in src/bin/geomutil/math2oogl/Makefile.in \
	src/bin/geomutil/maple2oogl/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-docDATA||g' ${WRKSRC}/${i}
.endfor

post-build:
	cd ${WRKSRC}/doc && /usr/bin/makeinfo --no-split --no-validate \
		-o geomview.info geomview.texi

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.3gv ${MAN3PREFIX}/man/man3
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.5gv ${MAN5PREFIX}/man/man5
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in OOGL.m.txt README README.gvplot geomview.pdf geomview-pt_BR.pdf \
	oogltour oogltour-pt_BR
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC}/doc/geomview.html \
		&& ${INSTALL_DATA} *.html ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/html/figs
	cd ${WRKSRC}/doc/figs \
		&& ${INSTALL_DATA} *.png ${DOCSDIR}/html/figs
	@${MKDIR} ${DOCSDIR}/html/pt_BR
	cd ${WRKSRC}/doc/geomview-pt_BR.html \
		&& ${INSTALL_DATA} *.html ${DOCSDIR}/html/pt_BR
	cd ${DOCSDIR}/html/pt_BR && ${LN} -sf ../figs .
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.c ${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.tcl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
