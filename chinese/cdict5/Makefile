# ex:ts=8
# Ports collection makefile for:	cdict5
# Date created:			Oct 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cdict5
PORTVERSION=	1.3
CATEGORIES=	chinese textproc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ijliao
DISTFILES=	cdict5.tgz cdict5-file.tgz
EXTRACT_ONLY=	cdict5.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese-English / English-Chinese dictionary

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm

IGNOREFILES=	cdict5-file.tgz

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/cdict5-file.tgz)
IGNORE=	"You have to obtain 21st Century Dictionary v5.0 data files yourself"
.endif

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local/lib/cdict5|${DATADIR}|" ${WRKSRC}/cdict5.h

do-install:
	@${MKDIR} ${DATADIR}
	${TAR} -zxf ${DISTDIR}/cdict5-file.tgz -C ${DATADIR} && \
		${MV} ${DATADIR}/cdict5-file/* ${DATADIR} && \
		${RMDIR} ${DATADIR}/cdict5-file
	${INSTALL_PROGRAM} ${WRKSRC}/cdict5 ${PREFIX}/bin
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} index
	${INSTALL_DATA} ${WRKSRC}/Index.gdbm ${DATADIR}

.include <bsd.port.post.mk>
