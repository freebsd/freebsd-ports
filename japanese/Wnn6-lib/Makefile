# New ports collection makefile for:	head files and libraries of Wnn6
# Date created:		11 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn6-lib
PORTVERSION=	2000.9.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn6/sdk_source/
DISTNAME=	Wnn6-SDK

MAINTAINER=	taoka@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
.else
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4
.endif

WRKSRC=		${WRKDIR}/src/contrib/im/Xsi
DOCDIR=		${PREFIX}/share/doc/ja-Wnn6-lib

INSTALLS_SHLIB=	yes

# Warning: we cannot use USE_IMAKE.
do-build:
	( cd ${WRKSRC} ; make World -f Makefile.ini )

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libwnn6.so.1.0 ${PREFIX}/lib/libwnn6.so
.endif
	${LN} -sf libwnn6_fromsrc.a ${PREFIX}/lib/libwnn6.a
	@${MKDIR} ${PREFIX}/include/wnn6/wnn
	@${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn6/wnn
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include <bsd.port.post.mk>
