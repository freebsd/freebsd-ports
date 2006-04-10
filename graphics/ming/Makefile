# New ports collection makefile for:	Ming
# Date created:		14 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.3.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LGPL'ed Flash 4/5 movie output library with many languages support

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif

CONFLICTS=	ja-ming-*

USE_GNOME=	gnometarget
USE_BISON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/ming \
		ac_cv_path_PYTHON=no
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I. -I.. -I${LOCALBASE}/include
LDFLAGS=	-L. -L.. -L${LOCALBASE}/lib
CFLAGS+=	${CPPFLAGS}

UTILS=		dbl2png listaction listaction_d listfdb listjpeg listmp3 \
		listswf listswf_d makefdb makeswf raw2adpcm swftoperl \
		swftophp swftopython
DOCS=		CREDITS ChangeLog HISTORY NEWS README TODO
DOCS_UTIL=	README TIPS TODO swftoperl.html

post-patch:
	@${REINPLACE_CMD} -e 's|@SHCFLAGS@|-fPIC -DPIC|g ; \
		 s|@SHLIBLDFLAGS@|-shared -Wl,-soname,$$(SHAREDLIB)|g ; \
		 s|@SHLIBEXT@|.so.4|g' ${WRKSRC}/Makefile.config.in
	@${REINPLACE_CMD} -e '/SHORT_SHLIBEXT/d' ${WRKSRC}/src/Makefile

do-install:
.for file in ${UTILS}
	${INSTALL_PROGRAM} ${WRKSRC}/util/${file} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/util/ming-config ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/ming
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/ming
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${PREFIX}/include/ming
	@${MKDIR} ${PREFIX}/include/ming/blocks
	${INSTALL_DATA} ${WRKSRC}/src/blocks/*.h ${PREFIX}/include/ming/blocks
	${INSTALL_DATA} ${WRKSRC}/libming.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libming.so.4 ${PREFIX}/lib
	${LN} -sf libming.so.4 ${PREFIX}/lib/libming.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/util
.for file in ${DOCS_UTIL}
	@${INSTALL_DATA} ${WRKSRC}/util/${file} ${DOCSDIR}/util
.endfor
.endif

.include <bsd.port.mk>
