PORTNAME=	datafusion
PORTVERSION=	52.1.0
CATEGORIES=	databases
PKGNAMESUFFIX=	-cli

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Apache DataFusion Command-line Interface
WWW=		https://datafusion.apache.org/user-guide/cli/ \
		https://github.com/apache/datafusion/tree/main/datafusion-cli \
		https://github.com/apache/datafusion

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	protoc:devel/protobuf

USES=		cargo llvm

CARGO_INSTALL_PATH=	datafusion-cli
MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		LLVM_CONFIG_PATH=${LLVM_CONFIG} \
		MYTHREAD_POSIX=1

PLIST_FILES=	bin/datafusion-cli

USE_GITHUB=	yes
GH_ACCOUNT=	apache

.include <bsd.port.mk>
