# New ports collection makefile for:	evilfinder
# Date created:				11 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evilfinder
PORTVERSION=	1.00
CATEGORIES=	games
MASTER_SITES=	http://lcamtuf.coredump.cx/
DISTNAME=	ef
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Numerologically determine the evilness of things

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WRAPPER)
RUN_DEPENDS+=	lynx:${PORTSDIR}/www/lynx
PLIST_SUB+=	WRAPPER=""
.else
PLIST_SUB+=	WRAPPER="@comment "
.endif

USE_REINPLACE=	yes

pre-everything::
.if !defined(WITHOUT_WRAPPER)
	@${ECHO_MSG} "********************************************"
	@${ECHO_MSG} "Define WITHOUT_WRAPPER to build without the"
	@${ECHO_MSG} "\"evilfinder\" wrapper, which makes the port"
	@${ECHO_MSG} "a web-oriented application."
	@${ECHO_MSG} "********************************************"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|evilnumbers.dat|${DATADIR}/evilnumbers.dat|; \
		s|./shuffle|${PREFIX}/bin/shuffle|" \
		${WRKSRC}/ef.c
.if !defined(WITHOUT_WRAPPER)
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|" \
		${FILESDIR}/evilfinder > ${WRKSRC}/evilfinder
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ef ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shuffle ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/evilnumbers.dat ${DATADIR}
.if !defined(WITHOUT_WRAPPER)
	${INSTALL_SCRIPT} ${WRKSRC}/evilfinder ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
