# New ports collection makefile for:	denemo
# Date created:				2001-02-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	denemo
PORTVERSION=	0.5.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		intl.4:${PORTSDIR}/devel/gettext \
		xml.5:${PORTSDIR}/textproc/libxml

GNU_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
SHARED=		denemo.conf denemo.keymaprc english.keymaprc french.keymaprc
DOCS=		AUTHORS ChangeLog DESIGN GOALS NEWS README TODO
DOCDIR=		share/doc/${PORTNAME}
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes

post-configure:
	${PERL} -pi -e "s:module12:module12 -lgnugetopt:g" ${WRKSRC}/Makefile
	${PERL} -pi -e "s:<wait.h:<sys/wait.h:g" ${WRKSRC}/*.c

pre-install:
	${ECHO_CMD} bin/${PORTNAME} > ${PLIST}
.for i in ${SHARED}
	${ECHO_CMD} share/denemo/$i >> ${PLIST}
.endfor
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/$i >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
	${ECHO_CMD} @dirrm share/denemo >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/denemo
	${INSTALL_PROGRAM} ${WRKSRC}/denemo ${PREFIX}/bin
.for i in ${SHARED}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/denemo
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
