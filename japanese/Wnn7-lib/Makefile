# New ports collection makefile for:	head files and libraries of Wnn7
# Date created:		01/07/16
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn7-lib
PORTVERSION=	98.10.28
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn6/sdk_source/
DISTNAME=	Wnn6-SDK-sources

MAINTAINER=	taoka@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
.else
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4
.endif

WRKSRC=		${WRKDIR}/src/contrib/im/Xsi
DOCDIR=		${PREFIX}/share/doc/ja-Wnn7-lib

INSTALLS_SHLIB=	yes

# Warning: we cannot use USE_IMAKE.
do-build:
	( cd ${WRKSRC} ; make World -f Makefile.ini )

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libwnn6_for_wnn7.so.1.0 ${PREFIX}/lib/libwnn6_for_wnn7.so
.endif
	${LN} -sf libwnn6_for_wnn7_fromsrc.a ${PREFIX}/lib/libwnn6_for_wnn7.a
	@${MKDIR} ${PREFIX}/include/wnn7/wnn
	@${INSTALL_DATA} ${WRKSRC}/Wnn/include/*.h ${PREFIX}/include/wnn7/wnn
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include <bsd.port.post.mk>
