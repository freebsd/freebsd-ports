# New ports collection makefile for:	ja-dvipdfm
# Date created:		07 July 2001
# Whom:			HIRATA Yasuyuki <yasu@asuka.net>
#
# $FreeBSD$
#

PORTNAME=		dvipdfm
PORTVERSION=		0.13.2c
PORTREVISION=		1
CATEGORIES=		japanese print
MASTER_SITES=		http://gaspra.kettering.edu/dvipdfm/

PATCH_SITES=		http://hamilcar.phys.kyushu-u.ac.jp/~hirata/dvipdfm/distfiles/
PATCHFILES=		${DISTNAME}-jpatch-p1c.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		yasu@asuka.net

BUILD_DEPENDS=		${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/japanese/ptex-common \
			${LOCALBASE}/share/doc/cmpsfont/README:${PORTSDIR}/print/cmpsfont
LIB_DEPENDS=		png:${PORTSDIR}/graphics/png
RUN_DEPENDS=		kpsewhich:${PORTSDIR}/japanese/ptex-common \
			${LOCALBASE}/share/doc/cmpsfont/README:${PORTSDIR}/print/cmpsfont

MAN1=			dvipdfm.1

WRKSRC=			${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS="${CXXFLAGS} -I${PREFIX}/include" \
			CFLAGS="${CFLAGS} -I${PREFIX}/include" \
			LDFLAGS=-L${PREFIX}/lib
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

post-install:
	strip ${PREFIX}/bin/dvipdfm
	strip ${PREFIX}/bin/ebb
	mktexlsr
	${MKDIR} ${PREFIX}/share/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/latex-support/dvipdfm.def ${PREFIX}/share/dvipdfm
#	${INSTALL_DATA} ${WRKSRC}/latex-support/hdvipdfm.def ${PREFIX}/share/dvipdfm
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/dvipdfm.tex ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/mwicks.bb ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/mwicks.jpeg ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.bb ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.eps ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.fig ${PREFIX}/share/texmf/doc/dvipdfm
	${INSTALL_DATA} ${WRKSRC}/doc/transistor.pdf ${PREFIX}/share/texmf/doc/dvipdfm
	( cd ${PREFIX}/share/texmf/doc/dvipdfm ; tex dvipdfm ; ${PREFIX}/bin/dvipdfm dvipdfm ; ${RM} dvipdfm.log dvipdfm.dvi )
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
