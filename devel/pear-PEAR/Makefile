# Ports collection makefile for:  pear-PEAR
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	PEAR
PORTVERSION=	1.4.4
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR Base System

BUILD_DEPENDS=	${PEARDIR}/Archive/Tar.php:${PORTSDIR}/archivers/pear-Archive_Tar	\
		${PEARDIR}/Console/Getopt.php:${PORTSDIR}/devel/pear-Console_Getopt	\
		${PEARDIR}/XML/RPC.php:${PORTSDIR}/devel/pear-XML_RPC
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes

FILES=		OS/Guess.php PEAR/ChannelFile/Parser.php PEAR/Command/Auth.xml		\
		PEAR/Command/Auth.php PEAR/Command/Build.xml PEAR/Command/Build.php	\
		PEAR/Command/Channels.xml PEAR/Command/Channels.php			\
		PEAR/Command/Common.php PEAR/Command/Config.xml PEAR/Command/Config.php	\
		PEAR/Command/Install.xml PEAR/Command/Install.php			\
		PEAR/Command/Package.xml PEAR/Command/Package.php			\
		PEAR/Command/Pickle.xml PEAR/Command/Pickle.php				\
		PEAR/Command/Registry.xml PEAR/Command/Registry.php			\
		PEAR/Command/Remote.xml PEAR/Command/Remote.php				\
		PEAR/Command/Mirror.xml PEAR/Command/Mirror.php				\
		PEAR/Command/Test.xml PEAR/Command/Test.php PEAR/Downloader/Package.php	\
		PEAR/Frontend/CLI.php PEAR/Installer/Role/Common.php			\
		PEAR/Installer/Role/Data.xml PEAR/Installer/Role/Data.php		\
		PEAR/Installer/Role/Doc.xml PEAR/Installer/Role/Doc.php			\
		PEAR/Installer/Role/Ext.xml PEAR/Installer/Role/Ext.php			\
		PEAR/Installer/Role/Php.xml PEAR/Installer/Role/Php.php			\
		PEAR/Installer/Role/Script.xml PEAR/Installer/Role/Script.php		\
		PEAR/Installer/Role/Src.xml PEAR/Installer/Role/Src.php			\
		PEAR/Installer/Role/Test.xml PEAR/Installer/Role/Test.php		\
		PEAR/Installer/Role.php PEAR/PackageFile/Generator/v1.php		\
		PEAR/PackageFile/Generator/v2.php PEAR/PackageFile/Parser/v1.php	\
		PEAR/PackageFile/Parser/v2.php PEAR/PackageFile/v2/rw.php		\
		PEAR/PackageFile/v2/Validator.php PEAR/PackageFile/v1.php		\
		PEAR/PackageFile/v2.php PEAR/REST/10.php PEAR/REST/11.php		\
		PEAR/Task/Postinstallscript/rw.php PEAR/Task/Replace/rw.php		\
		PEAR/Task/Unixeol/rw.php PEAR/Task/Windowseol/rw.php			\
		PEAR/Task/Common.php PEAR/Task/Postinstallscript.php			\
		PEAR/Task/Replace.php PEAR/Task/Unixeol.php PEAR/Task/Windowseol.php	\
		PEAR/Validator/PECL.php PEAR/Autoloader.php PEAR/Builder.php		\
		PEAR/ChannelFile.php PEAR/Command.php PEAR/Common.php PEAR/Config.php	\
		PEAR/Dependency.php PEAR/DependencyDB.php PEAR/Dependency2.php		\
		PEAR/Downloader.php PEAR/ErrorStack.php PEAR/Exception.php		\
		PEAR/Frontend.php PEAR/Installer.php PEAR/Packager.php			\
		PEAR/PackageFile.php PEAR/Registry.php PEAR/Remote.php PEAR/REST.php	\
		PEAR/RunTest.php PEAR/Validate.php PEAR/XMLParser.php package.dtd	\
		template.spec PEAR.php System.php
SCRIPTFILES=	pear2

.include <bsd.port.pre.mk>

pre-patch:
.for dosfile in ${FILES} scripts/pearcmd.php
	@${MV} ${WRKSRC}/${dosfile} ${WRKSRC}/${dosfile}.dos
	@${TR} -d '\r' < ${WRKSRC}/${dosfile}.dos > ${WRKSRC}/${dosfile}
.endfor

post-patch:
.for origfile in ${FILES}
	@${REINPLACE_CMD} -e 's|@pear_version@|${PORTVERSION}|g'	\
			-e 's|@PEAR-VER@|${PORTVERSION}|g'		\
			-e 's|@DATA-DIR@|${PEARDIR}|g'		\
		${WRKSRC}/${origfile}
.endfor
	@${SED} "s|@pear_version@|${PORTVERSION}|g" \
		${WRKSRC}/scripts/pearcmd.php > ${WRKSRC}/pear-${SCRIPTFILES}

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
