# New ports collection makefile for:	phpsh
# Date created:		2011-08-22
# Whom:			Ashish SHUKLA <ashish@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpsh
PORTVERSION=	20110513
CATEGORIES=	devel
MASTER_SITES=	http://wahjava.users.sourceforge.net/%SUBDIR%/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ashish

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	An interactive shell for PHP

USE_BZIP2=	yes
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes
USE_PHP=	pcre posix tokenizer

WANT_PHP_CLI=	yes

PLIST_SUB=	PORTNAME=${PORTNAME}

PYDISTUTILS_PKGVERSION=	1.3

MAN1=		phpsh.1

OPTIONS=	PCNTL	"Fork on every command (requires PHP extension pcntl)"	OFF

.include <bsd.port.options.mk>

.if defined(WITH_PCNTL)
USE_PHP+=	pcntl
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -Rl '%%PREFIX%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
