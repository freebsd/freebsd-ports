PORTNAME=	gettext-tiny
PORTVERSION=	0.3.2
CATEGORIES=	devel
MASTER_SITES=	https://ftp.barfooze.de/pub/sabotage/tarballs/ \
		http://ftp.barfooze.de/pub/sabotage/tarballs/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Replacements for tools typically used from the GNU gettext suite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	tar:xz
TOOLS=	msgfmt msgmerge
SCRIPTS=	xgettext

PLIST_FILES=	${TOOLS:C,^,bin/tiny-,} \
		${SCRIPTS:C,^,bin/tiny-,}

MAKE_ARGS=	prefix=${PREFIX}

do-install:
.for t in ${TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/$t ${STAGEDIR}${PREFIX}/bin/tiny-$t
.endfor
.for s in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/$s ${STAGEDIR}${PREFIX}/bin/tiny-$s
.endfor

.include <bsd.port.mk>

