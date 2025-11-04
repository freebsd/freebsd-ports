PORTNAME=	dfuzzer
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5
CATEGORIES=	devel sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	D-Bus fuzzer utility
WWW=		https://github.com/dbus-fuzzer/dfuzzer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome meson pkgconfig

USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	dbus-fuzzer

PLIST_FILES=	bin/dfuzzer \
		"@sample etc/dfuzzer.conf.sample"

OPTIONS_DEFINE=		MANPAGES

MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xsl>=0:textproc/docbook-xsl
MANPAGES_PLIST_FILES=	share/man/man1/dfuzzer.1.gz

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dfuzzer.conf \
		${STAGEDIR}${PREFIX}/etc/dfuzzer.conf.sample

.include <bsd.port.mk>
