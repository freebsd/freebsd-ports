PORTNAME=	clisp-hyperspec
PORTVERSION=	7.0
CATEGORIES=	devel lisp
MASTER_SITES=	http://ftp.lispworks.com/pub/software_tools/reference/
DISTNAME=	HyperSpec-7-0

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Common Lisp reference in HTML format, from LispWorks Ltd

# Converted from NO_CDROM
LICENSE=	HyperSpec
LICENSE_NAME=	HyperSpec
LICENSE_TEXT=	Commercial redistribution prohibited
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HyperSpec-Legalese.text ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HyperSpec-README.text ${STAGEDIR}${DOCSDIR}
	${CP} -r ${WRKSRC}/HyperSpec ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
