# New ports collection makefile for:	flux
# Date created:		18 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	flux
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.copyleft.no/projects/fluxlib/ \
		ftp://ftp.styx.net/projects/flux/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	High-level C library for development purposes

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=14
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
REGEX=		"s@EXTRA_DIST \+@EXTRA_DIST @g"

pre-configure:
.for M in examples include src util
	@${REINPLACE_CMD} -e ${REGEX} ${WRKSRC}/${M}/Makefile.am
.endfor
.for M in build cgi cipher comm fifobuf fstring log mem misc mt nvtp ph proc \
	random smtp sock tn url xml
	@${REINPLACE_CMD} -e ${REGEX} ${WRKSRC}/src/${M}/Makefile.am
.endfor
.for M in framework/application framework/application/src test
	@${REINPLACE_CMD} -e ${REGEX} ${WRKSRC}/util/${M}/Makefile.am
.endfor
.for M in smtp
	@${REINPLACE_CMD} -e ${REGEX} ${WRKSRC}/examples/${M}/Makefile.am
.endfor
	@${REINPLACE_CMD} -e "s@autoheader,@${AUTOHEADER},@g" ${WRKSRC}/aclocal.m4

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/flux
	${TAR} -C ${WRKSRC}/doc --exclude ChangeLog -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/flux --unlink -xf -
	@${FIND} ${PREFIX}/share/doc/flux | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${PREFIX}/share/doc/flux -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.for DOC in AUTHORS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/doc/flux
.endfor
.endif

.include <bsd.port.mk>
