# ports collection makefile for:	jigdo
# Date created:				23 July 2002
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	jigdo
PORTVERSION=	0.6.8
CATEGORIES=	ftp
MASTER_SITES=	http://home.in.tum.de/~atterer/jigdo/

MAINTAINER=	bra@fsn.hu

#BUILD_DEPENDS=	libwww-config:${PORTSDIR}/www/libwww
RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

MAN1=		jigdo-file.1 jigdo-lite.1 jigdo-mirror.1

USE_BZIP2=	yes
#USE_REINPLACE=	yes
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-libdb --disable-nls --without-gui
USE_GMAKE=	yes

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.jigdo

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

#post-patch:
#	@${REINPLACE_CMD} -e "s/gtk-config/${GTK_CONFIG}/g" ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500041
EXTRA_PATCHES=	${FILESDIR}/extra-glibc-getopt.h
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/jigdo-file

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
