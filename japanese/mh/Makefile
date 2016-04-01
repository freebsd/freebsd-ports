# Created by: Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
# $FreeBSD$

PORTNAME=	mh
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	2
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.laic.u-hyogo.ac.jp/pub/net/mh/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${VERSION}-JP-${JP_VERSION}

MAINTAINER=	CQG00620@nifty.ne.jp
COMMENT=	Rand MH mail handling system + Japanese patches

BUILD_DEPENDS=	jless:japanese/less
RUN_DEPENDS=	jless:japanese/less

VERSION=	6.8.4
JP_VERSION=	3.05

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-batchmode \
		--enable-apop=${PREFIX}/etc/pop.auth \
		--enable-jmandir=${MANPREFIX}/man/ja
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-Wno-return-type

USE_LDCONFIG=	yes

PORTDOCS=	00.READ.ME.1ST CHANGES.JP COMMANDS.JP FAQ.JP FEATURES.JP \
		INSTALL.JP OPTIONS.JP READ-ME.JP TODO.JP
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

CONFLICTS=	nmh-[0-9]*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s/-O /${CFLAGS} /g" ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmh.so.3
.for i in ap conflict dp fmtdump install-mh mhl post rcvdist rcvpack rcvstore rcvtty slocal spost
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mh/${i}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc-JP && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
