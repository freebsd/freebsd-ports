# New ports collection makefile for:	panorama
# Date created:				14 Sept 2000
# Whom:					Aaron VonderHaar <avh4@usa.net>
#
# $FreeBSD$
#

PORTNAME=	panorama
PORTVERSION=	0.13.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://alpha.gnu.org/gnu/

MAINTAINER=	avh4@usa.net

USE_GMAKE=	yes

WRKBLD=	${WRKDIR}/build
SHRDIR=	${PREFIX}/share/panorama
DOCDIR=	${PREFIX}/share/doc/panorama

do-configure:
	(cd ${WRKSRC}; ./configure --prefix=${WRKBLD})

do-install:
	(cd ${WRKSRC}; ${GMAKE} install)
	@echo "-----Installing binaries"
	${INSTALL_PROGRAM} ${WRKBLD}/bin/render ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@echo "-----Installing documentation (or what little there is of it)"
	${MKDIR} ${DOCDIR}
	${INSTALL_MAN} ${WRKBLD}/doc/[A-Z]* ${DOCDIR}/
	${MKDIR} ${DOCDIR}/developers
	${INSTALL_MAN} ${WRKBLD}/doc/developers/* ${DOCDIR}/developers/
	${MKDIR} ${DOCDIR}/users
	${INSTALL_MAN} ${WRKBLD}/doc/users/* ${DOCDIR}/users/
.endif
	@echo "-----Installing includes, libraries, plugins, and exmaples"
	${MKDIR} ${SHRDIR}
	(cd ${WRKBLD}; tar cpf - include lib scenes) \
		| (cd ${SHRDIR}; tar xpf -)
	@echo "-----Creating configuration files"
	${MKDIR} ${SHRDIR}/etc
	${INSTALL_DATA} ${WRKBLD}/etc/pluginrc ${SHRDIR}/etc/pluginrc
	@echo "echo [config-data] > ${SHRDIR}/etc/config"
	@echo "PluginConfigFile=${SHRDIR}/etc/pluginrc" > ${SHRDIR}/etc/config
	@echo "PluginPath=${SHRDIR}/lib/plugins" >> ${SHRDIR}/etc/config
	@echo "GradientPath=${SHRDIR}/lib/gradients" >> ${SHRDIR}/etc/config
	@echo "TexturePath=${SHRDIR}/lib/texture" >> ${SHRDIR}/etc/config
	@echo "IncludePath=${SHRDIR}/include" >> ${SHRDIR}/etc/config

post-install:
	${LDCONFIG} -m ${SHRDIR}/lib

.include <bsd.port.mk>
