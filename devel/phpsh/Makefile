# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpsh
PORTVERSION=	20110513
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.pirateparty.in/%SUBDIR%/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ashish

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	An interactive shell for PHP

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PHP=	pcre posix tokenizer

WANT_PHP_CLI=	yes

PLIST_SUB=	PORTNAME=${PORTNAME}

PYDISTUTILS_PKGVERSION=	1.3

MAN1=		phpsh.1

OPTIONS_DEFINE=	PCNTL
PCNTL_DESC=	Fork on every command (pcntl PHP extension)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCNTL}
USE_PHP+=	pcntl
.endif

post-patch:
	@${GREP} -Rl '%%PREFIX%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
