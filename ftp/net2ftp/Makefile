# Created by: Alexander Kriventsov
# $FreeBSD$

PORTNAME=	net2ftp
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.net2ftp.com/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP scripts to work with ftp

LICENSE=	GPLv2

USES=		zip
NO_BUILD=	YES
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ftp mysql pcre session zlib
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
			   ${MKDIR} ${STAGEDIR}$$dst ; \
		  else \
			   ${INSTALL_DATA} $$src ${STAGEDIR}$$dst ; \
		  fi \
	 done

install-conf: install-app
	 @cd ${WRKSRC}/files_to_upload ; \
	 ${INSTALL_DATA} settings.inc.php ${STAGEDIR}${WWWDIR}/settings.inc.php.sample ; \
	 ${INSTALL_DATA} settings_authorizations.inc.php ${STAGEDIR}${WWWDIR}/settings_authorizations.inc.php.sample ; \
	 ${INSTALL_DATA} settings_screens.inc.php ${STAGEDIR}${WWWDIR}/settings_screens.inc.php.sample

.include <bsd.port.mk>
