# Created by: Kostya Lukin <lukin@okbmei.msk.su>
# $FreeBSD$

PORTNAME=	adns
PORTVERSION=	1.5
CATEGORIES=	dns
MASTER_SITES=	http://www.chiark.greenend.org.uk/~ian/adns/ftp/
EXTRACT_SUFX=	.0~rc0.tar.gz

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Easy to use asynchronous-capable DNS client library and utilities

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.0~rc0

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

LIBVERSION=	1
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

BUILD_DEPENDS+=		gm4:${PORTSDIR}/devel/m4
CFLAGS+=		-Ds6_addr16=__u6_addr.__u6_addr16
CFLAGS+=		-Ds6_addr32=__u6_addr.__u6_addr32
MAKE_FLAGS+=		M4=gm4
#PATCH_SITES+=		https://people.debian.org/~lucab/deb/adns/:ipv6patch
#PATCHFILES+=		adns-ipv6.patch:ipv6patch
#PATCH_DIST_STRIP+=	-p1

DOCS=		COPYING GPL-vs-LGPL INSTALL README \
		README.html TODO changelog

TOSTRIP=	bin/adnsheloex \
		bin/adnsresfilter \
		bin/adnslogres \
		bin/adnshost \
		lib/libadns.so.1

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

post-stage:
.for f in ${TOSTRIP}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.endfor

.include <bsd.port.mk>
