# New ports collection makefile for:	cvsgraph
# Date created:				2001-02-21
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	cvsgraph
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.akhphd.au.dk/~bertho/cvsgraph/release/

MAINTAINER=	serge.gagnon.1@ulaval.ca
COMMENT=	Graph the life story of a file under CVS or RCS

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		cvsgraph.1
MAN5=		cvsgraph.conf.5

DOCDIR=		share/doc/${PORTNAME}
DOCS=		ChangeLog README
EXAMPLES=	cvsgraphwrapper.php mkimage.php
MORE_EXAMPLES=	README.Automatic_documentation checkoutlist commit_action.sh \
		commitinfo cvswrappers tag_action.sh taginfo
PLIST=		${WRKDIR}/pkg-plist
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gd-inc=${LOCALBASE}/include \
		--with-gd-lib=${LOCALBASE}/lib CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${PREFIX}/lib"
REINPLACE_ARGS=	-i ""

pre-patch:
	@${REINPLACE_CMD} -e "s:/home/bertho/tmp/cvstest:/home/ncvs:g" ${WRKSRC}/cvsgraph.conf

pre-install:
	${ECHO_CMD} bin/cvsgraph > ${PLIST}
	${ECHO_CMD} etc/cvsgraph.conf.sample >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
.for i in ${MORE_EXAMPLES}
	${ECHO_CMD} share/examples/${PORTNAME}/automatic_documentation/${i} >> ${PLIST}
.endfor
.for i in ${EXAMPLES}
	${ECHO_CMD} share/examples/${PORTNAME}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/examples/${PORTNAME}/automatic_documentation >> ${PLIST}
	${ECHO_CMD} @dirrm share/examples/${PORTNAME} >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${PREFIX}/etc/cvsgraph.conf.sample
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 ${PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}/automatic_documentation
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${PREFIX}/share/examples/${PORTNAME}
.endfor
.for i in ${MORE_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/contrib/automatic_documentation/${i} ${PREFIX}/share/examples/${PORTNAME}/automatic_documentation
.endfor
.endif

post-install:
	@${ECHO_CMD} " "
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
