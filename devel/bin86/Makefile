# New ports collection makefile for:	bin86
# Date created:				2000-10-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	bin86
PORTVERSION=	0.15.5
CATEGORIES=	devel
MASTER_SITES=	http://www.cix.co.uk/~mayday/

MAINTAINER=	trevor@FreeBSD.org

DOCS=		ChangeLog README README-0.4
DOCDIR=		share/doc/${PORTNAME}
MAN1=		as86.1 ld86.1
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	find ${WRKSRC} -type f -print0 | xargs -0 ${CHMOD} 644

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC} && \
		find -s ${WRKSRC} -perm 755 -type f -exec ${BASENAME} \{\} \; \
			| ${SED} -e 's:^:bin/:' >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO} "@dirrm " ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/*1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} `find ${WRKSRC} -type f -perm 755 |grep -v encap` \
		${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/as/as86_encap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
