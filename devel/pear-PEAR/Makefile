# Ports collection makefile for:  pear-PEAR
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	PEAR
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR Base System

BUILD_DEPENDS=	${PEARDIR}/Archive/Tar.php:${PORTSDIR}/archivers/pear-Archive_Tar	\
		${PEARDIR}/Console/Getopt.php:${PORTSDIR}/devel/pear-Console_Getopt	\
		${PEARDIR}/XML/RPC.php:${PORTSDIR}/devel/pear-XML_RPC
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		OS/Guess.php PEAR/Command/Auth.php PEAR/Command/Build.php \
		PEAR/Command/Common.php PEAR/Command/Config.php \
		PEAR/Command/Install.php PEAR/Command/Package.php \
		PEAR/Command/Registry.php PEAR/Command/Remote.php \
		PEAR/Command/Mirror.php PEAR/Frontend/CLI.php PEAR/Autoloader.php \
		PEAR/Command.php PEAR/Common.php PEAR/Config.php PEAR/Dependency.php \
		PEAR/Downloader.php PEAR/Exception.php PEAR/ErrorStack.php \
		PEAR/Builder.php PEAR/Installer.php PEAR/Packager.php PEAR/Registry.php \
		PEAR/Remote.php PEAR/RunTest.php PEAR.php System.php \
		package.dtd template.spec
SCRIPTFILES=	pear2

.include <bsd.port.pre.mk>

post-patch:
	@${SED} "s|@pear_version@|${PORTVERSION}|g" \
		${WRKSRC}/scripts/pearcmd.php > ${WRKSRC}/pear-${SCRIPTFILES}

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
