# New ports collection makefile for:   libofx
# Date created:        February 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#

PORTNAME=	libofx
PORTVERSION=	0.7.0
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LIB_DEPENDS=	osp.3:${PORTSDIR}/textproc/opensp

USE_GMAKE=	yes
USE_GNOME=	gnometarget
USE_LIBTOOL_VER=	15
USE_GETOPT_LONG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-doxygen --disable-dot \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README totest.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${TAR} -C ${WRKSRC}/doc -cf - html | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
