# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiarra
PORTVERSION=	20100212
PORTREVISION=	7
CATEGORIES=	japanese irc ipv6
MASTER_SITES=	http://www.clovery.jp/tiarra/archive/2010/02/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	IRC Proxy software

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6

USES=		perl5 tar:bzip2 shebangfix
USE_PERL5=	run
USE_RC_SUBR=	tiarra
SHEBANG_FILES=	tiarra makedoc
NO_BUILD=	yes
NO_ARCH=	yes

USERS=		${TIARRA_USER}
GROUPS=		${TIARRA_GROUP}

SUB_FILES=	pkg-message
SUB_LIST=	TIARRA_USER=${TIARRA_USER}

PLIST_SUB=	TIARRA_USER=${TIARRA_USER} \
		TIARRA_GROUP=${TIARRA_GROUP}

TIARRA_USER=	tiarra
TIARRA_GROUP=	tiarra

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/tiarra
	@${TAR} cfC - ${WRKSRC} . | \
		${TAR} xfC - ${STAGEDIR}${PREFIX}/tiarra
	@${MKDIR} ${STAGEDIR}${PREFIX}/tiarra/log
	@${CHMOD} o-rwx ${STAGEDIR}${PREFIX}/tiarra/log

.include <bsd.port.mk>
