# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.5
PORTREVISION=	2
CATEGORIES=	java www
MASTER_SITES=	ftp://ftp.sunet.se/pub/database/utils/orionserver/ \
		http://www.jollem.com/ \
		http://www.sebster.com/~elvis/
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${LOCALBASE}/linux-jdk1.3.0/bin/java:${PORTSDIR}/java/linux-jdk13

USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
ORION_DESTDIR=	${PREFIX}/${DISTNAME}
ORION_LINKDIR=	${PREFIX}/${PORTNAME}
PORTTITLE=	Orion Server
ORIONCTL_NAME=	orionctl
ORIONCTL_DEST=	${PREFIX}/bin/${ORIONCTL_NAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}.sh

.include <bsd.port.pre.mk>

do-install:
	@if [ -d ${ORION_DESTDIR} ]; then \
		${ECHO} "ERROR: The destination directory ${ORION_DESTDIR} already exists. Cancelling."; \
		exit 65; \
	fi
	@${MKDIR} ${ORION_DESTDIR}
	@${CP} -R ${WRKSRC}/* ${ORION_DESTDIR}
	@${CHMOD} 755 `find ${ORION_DESTDIR} -type d`
	@${CP} ${FILESDIR}/${ORIONCTL_NAME}  ${ORIONCTL_DEST}
	@${CHMOD} 755 ${ORIONCTL_DEST}
	@${LN} -s ${ORIONCTL_DEST} ${RC_SCRIPT}

post-install:
	@echo "${PORTTITLE} ${PORTVERSION} has been installed in ${ORION_DESTDIR}."

.include <bsd.port.post.mk>


# Portrevision from 1 to 2 (version is still 1.4.5)
# Changed reference to linux-jdk1.2.2 into linux-jdk1.3.0 in the shell script,
#     since the port depends on linux-jdk1.3.0.
# Fixed a few typos and other issues in the shell script
# No longer installing a link from ${PREFIX}/orion -> ${PREFIX}/orion1.4.5
# Making all directories under ${PREFIX}/orion1.4.5 a+x
# Added one mirror site for the DISTFILE
# Renamed shell script from `orion.sh' to `orionctl' (similar to `apachectl')
# Installing the shell script in the ${PREFIX}/bin/ directory and symlinking
#    from ${PREFIX}/etc/rc.d/orion.sh to the former file, making sure that the
#    shell script is +x
# Including the shell script in ${FILESDIR} instead of downloading

# TODO: Create a new account for Orion so it won't run as root
# TODO: Support restarting Orion with the shell script script
# TODO: Support obtaining status info from a running Orion instance
# TODO: Add a man page for `orionctl'
