# New ports collection makefile for:	head files and libraries of Wnn6
# Date created:		11 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn6-lib
PORTVERSION=	98.10.28
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.omronsoft.co.jp/pub/Wnn6/sdk_source/
DISTNAME=	Wnn6-SDK-sources

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

WRKSRC=		${WRKDIR}/src/contrib/im/Xsi
DOCDIR=		${PREFIX}/share/doc/ja-Wnn6-lib

INSTALLS_SHLIB=	yes

# Warning: we cannot use USE_IMAKE.
do-build:
	( cd $(WRKSRC) ; make World -f Makefile.ini )

.include <bsd.port.pre.mk>

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
