# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpsh
PORTVERSION=	20110513
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.pirateparty.in/%SUBDIR%/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ashish

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Interactive shell for PHP

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_PHP=	pcre posix tokenizer

WANT_PHP_CLI=	yes

PLIST_SUB=	PORTNAME=${PORTNAME}

PYDISTUTILS_PKGVERSION=	1.3


OPTIONS_DEFINE=	PCNTL
PCNTL_DESC=	Fork on every command (pcntl PHP extension)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCNTL}
USE_PHP+=	pcntl
.endif

post-patch:
	@${GREP} -Rl '%%ETCDIR%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%ETCDIR%%,${ETCDIR},g'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
