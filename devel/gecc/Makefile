# New ports collection makefile for:	gecc
# Date created:				2002-11-07
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	gecc
PORTVERSION=	20021119
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gecc

MAINTAINER=	trevor@FreeBSD.org

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500039
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
BROKEN=		"only works as a wrapper"
.else
BROKEN=		"getopt_long() problems"
.endif

BINS=		gecc geccd
DOCS=		AUTHORS COPYING ChangeLog NEWS TODO
DOCDIR=		share/doc/${PORTNAME}
.if ${OSVERSION} < 500039
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
.endif
GNU_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_PYTHON=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i'' -E

post-extract:
	${CP} ${FILESDIR}/README ${FILESDIR}/dashboard.h ${WRKSRC}
	${REINPLACE_CMD} "s=usr/bin=${LOCALBASE}/bin=g" ${WRKSRC}/geccmon

pre-install:
	${RM} -f ${PLIST}
.for ii in ${BINS} geccmon
	${ECHO_CMD} bin/`${BASENAME} ${ii}` >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
.for ii in ${DOCS} README
	${ECHO_CMD} ${DOCDIR}/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} "@dirrm " ${DOCDIR} >> ${PLIST}
.endif

do-install:
.for ii in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${ii} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/geccmon ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${PREFIX}/${DOCDIR}
.endfor
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.post.mk>
