# New ports collection makefile for:	tuxtype
# Date created:				Mon Aug  6 21:53:03 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	tuxtype
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	An educational typing tutor starring Tux the Linux Penguin

USE_SDL=	image mixer sdl
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_AUTOMAKE_VER=14
USE_GMAKE=	yes
USE_PERL5_BUILD=yes

pre-patch:
.for dirs in data images sounds
	@${PERL} -pi.orig -e \
		's|\$$\(prefix\)/tuxtype/README_IMAGES.TXT|${DOCSDIR}/README_IMAGES.TXT|; \
		s|\$$\(prefix\)/tuxtype/README_SOUNDS.TXT|${DOCSDIR}/README_SOUNDS.TXT|; \
		s|\$$\(prefix\)/tuxtype|${DATADIR}|' \
		${WRKSRC}/tuxtype/${dirs}/Makefile.am
.endfor
.for docs in docs/en ..
	@${PERL} -pi.orig -e 's|\$$\(prefix\)/tuxtype|${DOCSDIR}|' \
		${WRKSRC}/tuxtype/${docs}/Makefile.am
.endfor
.for files in graphics playgame
	@${PERL} -pi.orig -e 's|/usr/local/share/tuxtype|${DATADIR}|' \
		${WRKSRC}/tuxtype/${files}.h
.endfor

post-install:
.if defined(NOPORTDOCS)
	@${RM} -Rf ${DOCSDIR}
.endif

.include <bsd.port.mk>
