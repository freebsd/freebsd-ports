# New ports collection makefile for:	libiodbc
# Date created:				24 Mar 2000
# Whom:					erikhb@bgnett.no
#
# $FreeBSD$
#
# Note:  The location of ${INIDIR} and the installed name of the "odbctest"
#        binary were chosen such that this port does not conflict with
#        databases/unixODBC.

PORTNAME=	libiodbc
PORTVERSION=	3.0.5
CATEGORIES=	databases
MASTER_SITES=	http://www.iodbc.org/dist/

MAINTAINER=	ebakke@trolltech.com

USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
INIDIR=		${PREFIX}/etc/${PORTNAME}
CONFIGURE_ARGS=	--with-iodbc-inidir=${INIDIR}

post-install:
	@ ${MKDIR} ${PREFIX}/bin && ${INSTALL_PROGRAM} \
	  ${WRKSRC}/samples/odbctest ${PREFIX}/bin/iodbc-odbctest
	@ ${MKDIR} ${INIDIR} && \
	  ${INSTALL_DATA} ${WRKSRC}/etc/odbc*.ini.sample ${INIDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in AUTHORS COPYING ChangeLog NEWS README
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
