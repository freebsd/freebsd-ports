# New ports collection makefile for:	qcad
# Date created:		10 Dec 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad
PORTVERSION=	1.4.16
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	kde@freebsd.org

USE_QT_VER=	2
USE_REINPLACE=	yes
MAKE_ENV=	MOC="${MOC}" LIBQT="-l${QTNAME}" \
		QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}"

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/*.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcad ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
.for dir in cur fonts hatches libraries messages xpm
	${TAR} -C ${WRKSRC} --exclude CVS --exclude hydraulics -cf - ${dir} | \
		${TAR} -C ${DATADIR} --unlink -xf -
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude CVS -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${LN} -sf ${DOCSDIR} ${DATADIR}/doc
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples --exclude CVS -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
.endif

.include <bsd.port.post.mk>
