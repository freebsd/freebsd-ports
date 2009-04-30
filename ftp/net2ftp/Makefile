# New ports collection makefile for: net2ftp
# Date created:	  14 Apr 2009
# Whom:		   Alexander Kriventsov
#
# $FreeBSD$
#

PORTNAME=	net2ftp
PORTVERSION=	0.97
CATEGORIES=	ftp
MASTER_SITES=	http://www.net2ftp.com/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	avk@vl.ru
COMMENT=	 PHP scripts to work with ftp

USE_ZIP=	 YES
NO_BUILD=	YES
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	 ftp mysql pcre session zlib
.endif
#USE_DOS2UNIX=	YES

PLIST=	   ${WRKDIR}/plist

CFGFILES=	settings.inc.php settings_authorizations.inc.php settings_screens.inc.php

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

# When creating a package, empty directories will not be generated
# from the pkg tarball.  Therefore make sure no directories are empty.

post-patch:
	 @cd ${WRKSRC}/files_to_upload ; \
	 for emptydir in $$( ${FIND} . -type d -empty -print ) ; do \
		  ${TOUCH} $${emptydir}/.keep-me ; \
	 done
	 @cd ${WRKSRC}/files_to_upload ; \
	 ${FIND} . ! -type d ! -name "settings*.inc.php" | ${SORT} | \
		  ${SED} -e "s,^\.,%%WWWDIR%%,"	    >${PLIST} ; \
	 ${CAT} ${PKGDIR}/pkg-plist-chunk		  >>${PLIST} ; \
	 ${FIND} . -type d | ${SORT} -r | ${SED} \
		  -e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
		  -e "s,^\.,@dirrm %%WWWDIR%%,"	    >>${PLIST}

do-install: install-app install-conf

install-app:
	 @cd ${WRKSRC}/files_to_upload ; \
	 for src in $$( ${FIND} . ! -name "settings*.inc.php" ) ; do \
		  dst=${WWWDIR}$${src#.} ; \
		  if ${TEST} -d $$src ; then \
			   ${MKDIR} $$dst ; \
		  else \
			   ${INSTALL_DATA} $$src $$dst ; \
		  fi \
	 done

install-conf: install-app
	 @cd ${WRKSRC}/files_to_upload ; \
	 ${INSTALL_DATA} settings.inc.php ${WWWDIR}/settings.inc.php.sample ; \
	 ${INSTALL_DATA} settings_authorizations.inc.php ${WWWDIR}/settings_authorizations.inc.php.sample ; \
	 ${INSTALL_DATA} settings_screens.inc.php ${WWWDIR}/settings_screens.inc.php.sample
	 @cd ${WWWDIR} ; \
	 for CFGFILE in ${CFGFILES} ; do \
		  if ${TEST} ! -f $${CFGFILE} ; then \
			   ${CP} -p $${CFGFILE}.sample $${CFGFILE} ; \
		  fi \
	 done

post-install:
	 @${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
