# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpsh
PORTVERSION=	20110513
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://distfiles.pirateparty.in/ashish/ \
		LOCAL/ashish

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Interactive shell for PHP

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

USES=		python tar:bzip2
USE_PYTHON=	distutils autoplist
USE_PHP=	pcre posix tokenizer
NO_ARCH=	yes

WANT_PHP_CLI=	yes

PLIST_SUB=	PORTNAME=${PORTNAME}

PYDISTUTILS_PKGVERSION=	1.3

OPTIONS_DEFINE=	PCNTL
PCNTL_DESC=	Fork on every command (pcntl PHP extension)
PCNTL_USE=	PHP=pcntl

post-patch:
	@${GREP} -Rl '%%ETCDIR%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%ETCDIR%%,${ETCDIR},g'

.include <bsd.port.mk>
