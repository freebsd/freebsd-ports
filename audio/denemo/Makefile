# New ports collection makefile for:	denemo
# Date created:				2001-02-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	denemo
PORTVERSION=	0.5.9
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Graphical score editor

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		xml.5:${PORTSDIR}/textproc/libxml

GNU_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
SHARED=		denemo.conf denemo.keymaprc english.keymaprc french.keymaprc
DOCS=		AUTHORS ChangeLog DESIGN GOALS NEWS README TODO
DOCDIR=		share/doc/${PORTNAME}
USE_BISON=	yes
USE_GETOPT_LONG=yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes

pre-patch:
.for ii in analysis_highlighting.c easylyparser.c easylyparser.y \
	lyparserfuncs.c lyparserfuncs.h main.c playback.c print.c
	${MV} ${WRKSRC}/${ii} ${WRKSRC}/${ii}.orig
	${SED} -e "s:<wait.h:<sys/wait.h:g ; s:setkey:dsetkey:g" \
		< ${WRKSRC}/${ii}.orig > ${WRKSRC}/${ii}
.endfor

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
	${INSTALL_DATA} ${WRKSRC}/$i ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
