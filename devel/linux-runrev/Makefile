# New ports collection makefile for:	linux-runrev
# Date created:				13 November 2002
# Whom:					Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	runrev
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	devel linux
MASTER_SITES=	ftp://ftp.runrev.com/pub/revolution/ \
		http://www.runrev.com/revolution/engines11/unix/
PKGNAMEPREFIX=	linux-
DISTNAME=	linux
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	blackend@FreeBSD.org
COMMENT=	Revolution is a rapid application development environment

RUN_DEPENDS=	xanim:${PORTSDIR}/multimedia/xanim

NO_CDROM=	"Sale for profit is not permitted"

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/Revolution-${PORTVERSION}
DATADIR=	${PREFIX}/share/Revolution-${PORTVERSION}

BIN_FILES=	revolution
LIB_DIRS=	Databases components components/assistants \
		components/help components/help/Appendixes \
		components/help/tutorials \
		components/help/tutorials/exercises \
		components/help/tutorials/modules components/save \
		components/save/userobjects components/tools plugins

# revolution requires these to be in the same directory
LIB_FILES=	LicenseAgreement ReadMeFirst license.rev

# trick to work with space in directory names
# we replace space with _
LIB_DIRS_HACK=	External_SDK External_SDK/external_Data \
		External_SDK/external_Data/Basic_Toolbox_FAT \
		External_SDK/external_Data/MCexternal68K \
		External_SDK/external_Data/MCexternalCarbon \
		External_SDK/external_Data/MCexternalPPC Made_With_Logos \
		Made_With_Logos/Graphics components/global_environment \
		components/help/tutorials/exercises/Employee_Data \
		components/help/tutorials/exercises/Employee_Data/images \
		components/properties_palettes

post-patch:
	@${SED} -e "s|%%PREFIX%%|${DATADIR}|" ${FILESDIR}/wrapper.sh > \
		${WRKDIR}/wrapper.sh

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DATADIR}
#	@${TAR} -C ${WRKSRC} -cf - . | ${TAR} -C ${DATADIR} --unlink -xf -
# create dirs and install files with proper permissions
.for dir in ${LIB_DIRS}
	@${MKDIR} ${DATADIR}/${dir}
	@for file in ${WRKSRC}/${dir}/* ; \
	do \
		if [ -f "$${file}" ]; \
		then \
			${INSTALL_DATA} "$${file}" \
				${DATADIR}/${dir} ; \
		fi ; \
	done
.endfor
# additional dirs but with space in their names
.for dir in ${LIB_DIRS_HACK}
	@dir_processed=`${ECHO_CMD} ${dir} | ${TR} "_" " "` ; \
		${MKDIR} ${DATADIR}/"$${dir_processed}" ; \
		for file in ${WRKSRC}/"$${dir_processed}"/* ; \
		do \
			if [ -f "$${file}" ]; \
			then \
				${INSTALL_DATA} "$${file}" \
					${DATADIR}/"$${dir_processed}" ; \
			fi ; \
		done
.endfor
# extra lib files
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}/${file}
.endfor
# binaries
.for file in ${BIN_FILES}
	@${STRIP_CMD} ${WRKSRC}/${file}
	@${BRANDELF} -t Linux ${WRKSRC}/${file}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${DATADIR}/${file}
.endfor
# install wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${PREFIX}/bin/revolution

.include <bsd.port.post.mk>
