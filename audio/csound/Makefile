# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	4.08
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.maths.bath.ac.uk/pub/dream/newest/
DISTFILES=	Csound.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+=	Version${PORTVERSION:S/./_/}.Notes
.endif
DIST_SUBDIR=	csound
EXTRACT_ONLY=	Csound.tar.gz

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

RESTRICTED=	"no redistribution; no commercial use except to make music (see http://mitpress.mit.edu/e-books/csound/fpage/FAQml/faq/faq.html#THE CSOUND COPYRIGHT ISSUES)"

MAKE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

pre-build:
	${RM} -f ${PLIST}
.for i in bin/csound share/csound/csound.dat
	${ECHO} ${i} >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	${ECHO} share/doc/csound/Version${PORTVERSION:S/./_/}.Notes >> ${PLIST}
	${ECHO} "@dirrm share/doc/csound" >> ${PLIST}
.endif
	${ECHO} "@dirrm share/csound" >> ${PLIST}

post-patch:
	${PERL} -pi -e "s:PREFIX:${PREFIX}:g" ${WRKSRC}/getstring.c

do-install:
	${MKDIR} ${PREFIX}/share/csound
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/csound
	${INSTALL_DATA} ${_DISTDIR}/Version${PORTVERSION:S/./_/}.Notes \
		${PREFIX}/share/doc/csound
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/csound ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/csound.txt ${PREFIX}/share/csound/csound.dat

post-clean:
	${RM} -f ${PLIST}

.include <bsd.port.mk>
