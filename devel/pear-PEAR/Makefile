# Ports collection makefile for:  pear-PEAR
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	PEAR
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Base System

BUILD_DEPENDS=	${PEARDIR}/Archive/Tar.php:${PORTSDIR}/archivers/pear-Archive_Tar	\
		${PEARDIR}/Console/Getopt.php:${PORTSDIR}/devel/pear-Console_Getopt
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		PEAR.php System.php PEAR/Autoloader.php \
		PEAR/Command.php PEAR/Command/Auth.php PEAR/Command/Build.php \
		PEAR/Command/Common.php PEAR/Command/Config.php \
		PEAR/Command/Install.php PEAR/Command/Package.php \
		PEAR/Command/Registry.php PEAR/Command/Remote.php \
		PEAR/Command/Mirror.php PEAR/Common.php PEAR/Config.php \
		PEAR/Dependency.php PEAR/Frontend/CLI.php PEAR/Builder.php \
		PEAR/Installer.php PEAR/Packager.php PEAR/Registry.php \
		PEAR/Remote.php OS/Guess.php package.dtd template.spec

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
