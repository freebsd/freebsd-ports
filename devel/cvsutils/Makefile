# New ports collection makefile for:	cvsutils
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvsutils
PORTVERSION=	2003.02.03
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.iDaemons.org/pub/distfiles/
MASTER_SITE_SUBDIR=	knu

MAINTAINER=	knu@FreeBSD.org
COMMENT=	CVS utilities which facilitate working with local working directories

USE_BZIP2=	yes
USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_AUTOMAKE_VER=15
USE_AUTOCONF_VER=253
AUTOMAKE_ARGS=	--add-missing

MAN1=		cvsutils.1
MANCOMPRESSED=	no

pre-configure:
	cd ${WRKSRC} ; ${ACLOCAL}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog FAQ NEWS README TODO 
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
