# New ports collection makefile for:	cvs2svn
# Date created:		1 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	cvs2svn
PORTVERSION=	0.0.938
CATEGORIES=	converters devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky

MAINTAINER=	perky@FreeBSD.org
COMMENT=	CVS to Subversion Repository Converter

RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
USE_BZIP2=	yes

post-patch:
.for script in cvs2svn profile-cvs2svn verify-cvs2svn \
		dump-db show-db
	@${LN} ${WRKSRC}/${script}.py ${WRKSRC}/${script}
.endfor
	@${INSTALL_DATA} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
