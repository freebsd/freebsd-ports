# New ports collection makefile for:	vtcl
# Date Created:		29 May 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	vtcl
PORTVERSION=	1.6.1a1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.6.1.a1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Application Development Environment For the TCL/TK language

LICENSE=	GPLv2

NO_BUILD=	yes

USE_TK=		yes
USE_DOS2UNIX=	configure
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e \
		's|wish8.5|${WISH:T}| ; \
		 s|/usr/local/bin|${LOCALBASE}/bin|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -i "" -e \
		's|require -exact Tk|require Tk|' ${WRKSRC}/lib/tkcon.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vtcl ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/vtcl
.for data in ChangeLog README vtcl.tcl
	${INSTALL_DATA} ${WRKSRC}/${data} ${PREFIX}/lib/vtcl
.endfor
	@${MKDIR} ${PREFIX}/lib/vtcl/images
.for sufx in gif ppm xbm xpm
	${INSTALL_DATA} ${WRKSRC}/images/*.${sufx} ${PREFIX}/lib/vtcl/images
.endfor
	@${MKDIR} ${PREFIX}/lib/vtcl/images/edit
	${INSTALL_DATA} ${WRKSRC}/images/edit/*.gif ${PREFIX}/lib/vtcl/images/edit
	@${MKDIR} ${PREFIX}/lib/vtcl/lib
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${PREFIX}/lib/vtcl/lib)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/sample
	@(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/sample)
	@${MKDIR} ${EXAMPLESDIR}/demo
	@(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/demo)
.endif

.include <bsd.port.mk>
