# New ports collection makefile for:	fistgen
# Date created:		2006-07-20
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	fistgen
PORTVERSION=	0.1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.filesystems.org/pub/fistgen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language for describing stackable filesystems

GNU_CONFIGURE=	yes
SUB_FILES=	pkg-message
PORTDOCS=	README INSTALL
MAN8=		fistgen.8
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	TEMPLATES	"Install FiST templates" on \
		EXAMPLES	"Install sample filesystems" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_TEMPLATES)
PLIST_SUB+=	TEMPLATES=""
.else
PLIST_SUB+=	TEMPLATES="@comment "
.endif
.if !defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-install:
.if !defined(WITHOUT_TEMPLATES)
	@${MKDIR} ${DATADIR}
	@${TAR} -cf - -C ${WRKSRC} templates | \
		${TAR} -xf - -C ${DATADIR}
# Make sure that the premissions correct
	@${FIND} ${DATADIR} -exec ${CHOWN} ${SHAREOWN} {} \;
.endif
.if !defined(WITHOUT_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -cf - -C ${WRKSRC} copyfs cryptfs gzipfs uuencodefs tests | \
		${TAR} -xf - -C ${EXAMPLESDIR}
# Make sure that the premissions correct
	@${FIND} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${EXAMPLESDIR} -exec ${CHOWN} ${SHAREOWN} {} \;
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
