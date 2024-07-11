PORTNAME=	freebsd-update-notify
DISTVERSION=	0.1.1-6
DISTVERSIONSUFFIX=	-gf703b73
CATEGORIES=	deskutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Notify desktop user when FreeBSD updates are available
WWW=		https://github.com/outpaddling/freebsd-update-notify

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zenity:x11/zenity auto-admin>=0.8.0:sysutils/auto-admin

USE_GITHUB=	yes

GH_ACCOUNT=	outpaddling

NO_BUILD=	yes
NO_ARCH=	yes

CONF_DIR=	${PREFIX}/etc/freebsd-update-notify

PLIST_FILES=	libexec/freebsd-update-notify \
		libexec/freebsd-update-cron \
		share/man/man8/freebsd-update-notify.8.gz \
		"@sample etc/freebsd-update-notify/freebsd-update-notify.conf.sample" \
		"@sample etc/freebsd-update-notify/freebsd-update-notify.crontab.sample etc/cron.d/freebsd-update-notify" \
		"@dir etc/cron.d"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/freebsd-update-notify
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update-notify \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update-cron \
		${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/freebsd-update-notify.conf \
		${STAGEDIR}${CONF_DIR}/freebsd-update-notify.conf.sample
	${INSTALL_DATA} ${WRKSRC}/freebsd-update-notify.crontab \
		${STAGEDIR}${CONF_DIR}/freebsd-update-notify.crontab.sample
	${INSTALL_MAN} ${WRKSRC}/freebsd-update-notify.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
