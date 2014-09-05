# Created by: Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
# $FreeBSD$

PORTNAME=	mh
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	1
CATEGORIES=	japanese mail
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.laic.u-hyogo.ac.jp/pub/net/mh/
MASTER_SITE_SUBDIR=	motoyuki
DISTNAME=	${PORTNAME}-${VERSION}-JP-${JP_VERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Rand MH mail handling system + Japanese patches

BUILD_DEPENDS=	jless:${PORTSDIR}/japanese/less
RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

VERSION=	6.8.4
JP_VERSION=	3.05

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-batchmode \
		--enable-apop=${PREFIX}/etc/pop.auth --enable-rpop
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-Wno-return-type

USE_LDCONFIG=	yes

PORTDOCS=	00.READ.ME.1ST CHANGES.JP COMMANDS.JP FAQ.JP FEATURES.JP \
		INSTALL.JP OPTIONS.JP READ-ME.JP TODO.JP
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

CONFLICTS=	nmh-[0-9]*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e "s/-O /${CFLAGS} /g" ${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc-JP && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
