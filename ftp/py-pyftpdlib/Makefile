# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	pyftpdlib
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	ftp python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python FTP server library

LICENSE=	MIT

USE_PYTHON=		2
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=		SENDFILE OPENSSL
OPTIONS_DEFAULT=	SENDFILE OPENSSL
SENDFILE_DESC=		Enable sendfile(2) support
OPENSSL_DESC=		Enable FTP over SSL/TLS (RFC4217)

# Workaround ports infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSENDFILE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pysendfile>0:${PORTSDIR}/net/py-pysendfile
.endif

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}openssl>0:${PORTSDIR}/security/py-openssl
.endif

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/demo/ ${EXAMPLESDIR}
.endif

test: build
	${TOUCH} ${WRKSRC}/test/__init__.py
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
