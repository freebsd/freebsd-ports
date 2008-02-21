# New ports collection makefile for:	kb
# Date created:		June 5, 2007
# Whom:			Diane Bruce <db@db.net>
#
# $FreeBSD$

PORTNAME=	kb
PORTVERSION=	7.09
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.db.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTFILES=	kb_src-${PORTVERSION}.tar.gz kb_inst-${PORTVERSION}.tar.gz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio contest logger

USE_XLIB=	yes
USE_GNOME=	libgnome gtk20 libbonobo
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${FILESDIR}/pkg_message

pre-configure:
	@${CP}	${FILESDIR}/Makefile ${WRKSRC}
.if exists(/usr/include/dev/speaker/speaker.h)
	@${REINPLACE_CMD} -e 's|-UBSDSOUND|-DBSDSOUND="<dev/speaker/speaker.h>"|' ${WRKSRC}/Makefile
.elif  exists(/usr/include/machine/speaker.h)
	@${REINPLACE_CMD} -e 's|-UBSDSOUND|-DBSDSOUND="<machine/speaker.h>"|' ${WRKSRC}/Makefile
.endif
	@${RM}	${WRKSRC}/kb_server
	@${RM}	${WRKSRC}/kb
	@${CP}	${FILESDIR}/bsd_bells.c ${WRKSRC}

do-install:
	@${INSTALL_SCRIPT}	${FILESDIR}/kbserver ${LOCALBASE}/etc/rc.d
	${INSTALL_SCRIPT}	${FILESDIR}/kb ${LOCALBASE}/bin
	${INSTALL_PROGRAM}	${WRKSRC}/kb ${LOCALBASE}/bin/kb_bin
	${INSTALL_PROGRAM}	${WRKSRC}/kb_server ${LOCALBASE}/sbin
	${MKDIR}		${DATADIR}
.for f in ${WRKSRC}/COUNTY.CQP ${WRKSRC}/DEFAULT.INI \
	${WRKSRC}/CALL_LIB.LST ${WRKSRC}/CALL_SS.LST \
	${WRKSRC}/CALL_FD.LST  ${WRKSRC}/HELP.LST \
	${WRKSRC}/COUNTRY.LST ${WRKSRC}/HELPFD.LST \
	${WRKSRC}/SECTION.LST ${WRKSRC}/STATE.LST
	${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
.endfor
	@${CAT}	${PKGMESSAGE}

.include <bsd.port.mk>
