# New ports collection makefile for:	P4DB
# Date created:		2 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	p4db
PORTVERSION=	2.01
CATEGORIES=	devel www
MASTER_SITES=	http://www.mydata.se/ftp/P4DB/
DISTNAME=	${PORTNAME:U}_${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Web/Perforce Browser

RUN_DEPENDS=	p4:${.CURDIR}/../perforce

USE_PERL5=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PATCH_WRKSRC=	${WRKSRC}/${PORTNAME}

FQDN!=		hostname
P4DB_HOME=	${LOCALBASE}/perforce/${PORTNAME}

# These variables are all configurable.
PERFORCE_USER?=		p4admin
PERFORCE_GROUP?=	p4admin
PERFORCE_HOME?=		${LOCALBASE}/perforce
PERFORCE_PORT?=		1666

post-extract:
	${MKDIR} ${WRKSRC}/${PORTNAME}/www
	${TAR} -xf ${WRKSRC}/cgi_files.tar -C ${WRKSRC}/${PORTNAME}/www/
	${RM} -f ${WRKSRC}/${PORTNAME}/www/Makefile ${WRKSRC}/${PORTNAME}/www/p4jdb/*.java
	${CP} -p ${WRKSRC}/README.html ${WRKSRC}/${PORTNAME}/www/
	${CP} ${WRKSRC}/P4DB.conf.txt ${WRKSRC}/${PORTNAME}/P4DB.conf.sample
	cd ${WRKSRC}; for f in P4DB.shortcuts*.txt; do \
		${CP} $${f} ${PORTNAME}/$${f}.sample; \
	done

post-patch:
	${PERL} -pi \
		-e 's,!!PREFIX!!,${PREFIX},g;' \
		-e 's,!!PERFORCE_USER!!,${PERFORCE_USER},g;' \
		-e 's,!!PERFORCE_GROUP!!,${PERFORCE_GROUP},g;' \
		-e 's,!!PERFORCE_PORT!!,${PERFORCE_PORT},g;' \
		-e 's,!!FQDN!!,${FQDN},g;' \
		${WRKSRC}/${PORTNAME}/P4DB.conf.sample
	${FIND} ${WRKSRC}/${PORTNAME} -name '*.orig' -delete

do-install:
	${MKDIR} ${P4DB_HOME}/www
	${CP} -Rp ${WRKSRC}/${PORTNAME}/* ${P4DB_HOME}/
	${CHOWN} -R ${PERFORCE_USER}:${PERFORCE_GROUP} ${P4DB_HOME}
.for f in P4DB.conf P4DB.shortcuts.txt P4DB.shortcuts2.txt
	if [ ! -f ${P4DB_HOME}/${f} ]; then \
		${CP} -p ${P4DB_HOME}/${f}.sample ${P4DB_HOME}/${f}; \
	fi
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${P4DB_HOME}/doc
	cd ${WRKSRC}; ${INSTALL_DATA} P4CGI.html README.html ${P4DB_HOME}/doc/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
