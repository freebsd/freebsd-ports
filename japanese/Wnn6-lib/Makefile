# New ports collection makefile for:	head files and libraries of Wnn6
# Version required:	99.10.28
# Date created:		11 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Wnn6-SDK-sources
PKGNAME=	ja-Wnn6-lib-98.10.28
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn6/sdk_source/

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

WRKSRC=		${WRKDIR}/src/contrib/im/Xsi
DOCDIR=		${PREFIX}/share/doc/ja-Wnn6-lib

# Warning: we cannot use USE_IMAKE.
do-build:
	( cd $(WRKSRC) ; make World -f Makefile.ini )

.include <bsd.port.pre.mk>

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libwnn6.so.1.0 ${PREFIX}/lib/libwnn6.so
.endif
	${LN} -sf libwnn6_fromsrc.a ${PREFIX}/lib/libwnn.a
	${LN} -sf libwnn6_fromsrc.a ${PREFIX}/lib/libwnn6.a
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/wnn
	@${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include <bsd.port.post.mk>
