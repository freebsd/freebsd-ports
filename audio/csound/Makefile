# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	4.12
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.maths.bath.ac.uk/pub/dream/newest/
DISTFILES=	Csound${PORTVERSION}.tar.gz
DIST_SUBDIR=	csound
EXTRACT_ONLY=	Csound${PORTVERSION}.tar.gz

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

RESTRICTED=	"no redistribution; no commercial use except to make music (see http://mitpress.mit.edu/e-books/csound/fpage/FAQml/faq/faq.html#THE CSOUND COPYRIGHT ISSUES)"

MAKE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
NO_WRKSUBDIR=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes

pre-build:
	find ${WRKDIR} -type f -exec ${CHMOD} 644 \{\} \;

post-build:
	${RM} -f ${PLIST}
	@for i in `find ${WRKDIR} -type f -perm 755`; do \
		${ECHO} bin/`${BASENAME} $${i}` >> ${PLIST}; \
	done
	${ECHO} share/csound/csound.dat >> ${PLIST}
	${ECHO} "@dirrm share/csound" >> ${PLIST}

post-patch:
	${PERL} -pi -e "s:PREFIX:${PREFIX}:g" ${WRKSRC}/getstring.c

do-install:
	${MKDIR} ${PREFIX}/share/csound
	${INSTALL_DATA} ${WRKSRC}/csound.txt ${PREFIX}/share/csound/csound.dat
	for i in `find ${WRKDIR} -type f -perm 755`; do \
		${INSTALL_PROGRAM} $${i} ${PREFIX}/bin ; \
	done

.include <bsd.port.mk>
