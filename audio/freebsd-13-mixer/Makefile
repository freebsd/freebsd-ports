PORTNAME=	freebsd-13-mixer
DISTVERSION=	13.0.0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Original mixer(8) from FreeBSD 13.0
WWW=		https://github.com/0mp/freebsd-13-mixer

LICENSE=	PD

DEPRECATED=	End of life, please use the base system mixer(8) utility.
EXPIRATION_DATE=2026-06-15

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	0mp

MAKE_ENV=	BINDIR=${PREFIX}/sbin \
		SHAREDIR=${PREFIX}/share

PLIST_FILES=	sbin/mixer \
		share/man/man8/mixer.8.gz

.include <bsd.port.mk>
