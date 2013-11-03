# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	gphpedit
PORTVERSION=	0.9.80
PORTREVISION=	5
CATEGORIES=	editors gnome
MASTER_SITES=	http://www.gphpedit.org/download/store/ \
		http://ftp.ceid.upatras.gr/pub/linux/gentoo/distfiles/ \
		http://www.jolupatech.info/crux/gphpedit/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	PHP, HTML, and CSS development environment for GNOME 2.x

DEPRECATED=	No longer maintaned upstream
EXPIRATION_DATE=	2013-12-01

USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgtkhtml
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

.if !defined(WITHOUT_PHP)
USE_PHP=	yes
WANT_PHP_CLI=	yes
.endif

.if !defined(WITHOUT_PHPDOC)
RUN_DEPENDS+=	${LOCALBASE}/share/doc/php-en/about.html:${PORTSDIR}/lang/php_doc
.endif

NO_STAGE=	yes
pre-everything::
.if !defined(WITHOUT_PHP) || !defined(WITHOUT_PHPDOC)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
.endif
.if !defined(WITHOUT_PHP)
	@${ECHO_MSG} "WITHOUT_PHP=yes to not install php, debug script will not work without it."
.endif
.if !defined(WITHOUT_PHPDOC)
	@${ECHO_MSG} "WITHOUT_PHPDOC=yes to not install php_doc, help will be disable."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share|${PREFIX}/share|g' \
		${WRKSRC}/src/main.h
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/calltip.c ${WRKSRC}/src/main_window.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/tab.c

pre-build:
	@cd ${WRKSRC}/src/gtkscintilla2 && ${GMAKE} clean

.include <bsd.port.mk>
