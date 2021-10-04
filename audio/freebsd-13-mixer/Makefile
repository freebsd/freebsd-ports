PORTNAME=	freebsd-13-mixer
DISTVERSION=	13.0.0
CATEGORIES=	audio

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Original mixer(8) from FreeBSD 13.0

LICENSE=	PD

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	0mp

MAKE_ENV=	BINDIR=${PREFIX}/sbin \
		SHAREDIR=${PREFIX}/share

PLIST_FILES=	sbin/mixer \
		share/man/man8/mixer.8.gz

.include <bsd.port.mk>
