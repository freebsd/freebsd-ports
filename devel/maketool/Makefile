# New ports collection makefile for:	maketool
# Date created:				2002-10-15
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	maketool
PORTVERSION=	0.8.4
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://home.alphalink.com.au/~gnb/maketool/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI interface for make or gmake

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2

DOCS=		COPYING COPYRIGHT ChangeLog TODO
GNU_CONFIGURE=	yes
MAN1=		maketool.1
PLIST=		${WRKDIR}/pkg-plist
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	atk glib20 gtk20 pango

post-patch:
	${REINPLACE_CMD} -e "s,-Wpointer-arithmetic,," ${WRKSRC}/configure

pre-install:
	${ECHO_CMD} bin/maketool > ${PLIST}
.for ii in make maketool_client
	${ECHO_CMD} libexec/maketool/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm libexec/maketool >> ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/doc/maketool/${ii} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/doc/maketool >> ${PLIST}
.endif
	cd ${WRKSRC}/doc/help/C/help && ${LS} | ${SED} -e \
		"s:^:share/maketool/help/C/:g" >> ${PLIST}
	cd ${WRKSRC}/doc/help/C && ${LS} *dat *gif | ${SED} -e \
		"s:^:share/maketool/help/C/:g" >> ${PLIST}
.for ii in autoconf-dist autoconf-maint automake imake
	${ECHO_CMD} share/maketool/${ii}.mk >> ${PLIST}
.endfor
.for ii in /help/C /help /
	${ECHO_CMD} @dirrm share/maketool${ii} >> ${PLIST}
.endfor
.for ii in cs ja
	${ECHO_CMD} share/locale/${ii}/LC_MESSAGES/maketool.mo >> ${PLIST}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
