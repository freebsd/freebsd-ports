# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	impact
PORTVERSION=	0.7.06.038
PORTEPOCH=	1
CATEGORIES=	cad java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
DISTNAME=	Impact-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Finite Element Program Suite

RUN_DEPENDS=	java3d>0:${PORTSDIR}/java/java3d

WRKSRC=		${WRKDIR}/Impact
NO_BUILD=	yes

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

DATADIR=	${JAVASHAREDIR}/Impact

SUB_FILES=	impact impactgui

PLIST=		${WRKDIR}/PLIST

pre-install:
	@${ECHO_CMD} -n > ${PLIST}
	@${ECHO_CMD} "bin/impact" >> ${PLIST}
	@${ECHO_CMD} "bin/impactgui" >> ${PLIST}
	@(cd ${WRKDIR} && ${FIND} Impact ! -type d | ${GREP} -v \
		-e "CVS" -e "lib_j3d" -e "\.bat" -e "\.dll" -e "\.ico" \
		-e "\.jnilib" -e "\.sh" -e "\.so" | ${SORT} | \
		${SED} "s|^Impact|%%DATADIR%%|" >> ${PLIST})
	@(cd ${WRKDIR} && ${FIND} Impact -type d | ${GREP} -v \
		-e "CVS" -e "lib_j3d" -e "\.bat" -e "\.dll" -e "\.ico" \
		-e "\.jnilib" -e "\.sh" -e "\.so" | ${SORT} -r | \
		${SED} "s|^Impact|@dirrm %%DATADIR%%|" >> ${PLIST})

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/impact ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/impactgui ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@(${TAR} -C ${WRKSRC} --exclude "CVS" --exclude "lib_j3d" \
		--exclude "*.bat" --exclude "*.dll" --exclude "*.ico" \
		--exclude "*.jnilib" --exclude "*.sh" --exclude "*.so" \
		-cf - . | ${TAR} -C ${DATADIR} --unlink -xf -)
	@${FIND} ${DATADIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGPR}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
