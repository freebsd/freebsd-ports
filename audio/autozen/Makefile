# New ports collection makefile for:	autozen
# Date created:				2000-09-16
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	autozen
PORTVERSION=	1.2.1
CATEGORIES=	audio
MASTER_SITES=	http://www.linuxlabs.com/software/download/
DISTNAME=	AutoZen-${PORTVERSION}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
MAKE_ENV=	GTK_CONFIG=${GTK_CONFIG}
WRKSRC=		${WRKDIR}/${PORTNAME}-1.2

DOC_FILES=	CHANGES COPYING
DATA_FILES=	deep-relax.seq relax.seq test.seq test2.seq test3.seq

post-patch:
	@${PERL} -pi -e "s=X11BASE=${X11BASE}=g" ${WRKSRC}/autozen.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autozen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/seq2wav ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/autozen
.for i in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/autozen
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/autozen
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/autozen
.endfor
.endif
.include <bsd.port.mk>
