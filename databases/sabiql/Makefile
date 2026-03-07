PORTNAME=	sabiql
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	0
CATEGORIES=	databases

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Fast, driver-less TUI to browse, query, and edit PostgreSQL databases
WWW=		https://github.com/riii111/sabiql

LICENSE=	APACHE20 BSD0CLAUSE BSD2CLAUSE BSD3CLAUSE BSL CDLA20 ISCL MIT \
		MPL20 UNICODE UNLICENSE WTFPL ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_CDLA20=	Community Data License Agreement – Permissive, Version 2.0
LICENSE_NAME_UNICODE=	UNICODE, INC. LICENSE AGREEMENT - DATA FILES AND SOFTWARE
LICENSE_TEXT_CDLA20=	See https://cdla.dev/permissive-2-0/
LICENSE_TEXT_UNICODE=	See https://www.unicode.org/copyright.html
LICENSE_PERMS_CDLA20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_UNICODE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	riii111

PLIST_FILES=	bin/sabiql

OPTIONS_DEFINE=		ER_DIAGRAMS
OPTIONS_DEFAULT=	ER_DIAGRAMS

ER_DIAGRAMS_DESC=		Enable support for E-R diagrams
ER_DIAGRAMS_RUN_DEPENDS=	dot:graphics/graphviz

.include <bsd.port.mk>
