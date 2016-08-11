# Created by: Rod Kay <rodakay@internode.on.net>
# $FreeBSD$

PORTNAME=	simple_components
PORTVERSION=	4.13
CATEGORIES=	devel
MASTER_SITES=	http://www.dmitry-kazakov.de/ada/
DISTNAME=	components_${PORTVERSION:S/./_/}

MAINTAINER=	rodakay@internode.on.net
COMMENT=	Simple Ada Components

LICENSE=	GPLv2 GMGPL
LICENSE_COMB=	multi

BUILD_DEPENDS=	gprbuild:devel/gprbuild

USES=		ada tar:tgz
DEST=		${STAGEDIR}${PREFIX}
NO_WRKSUBDIR=	yes

CS=		components
SV=		${CS}-connections_server
HS=		${SV}-http_server
PROJECT_LIST=	strings_edit tables ${CS} ${CS}-sqlite ${CS}-odbc \
		${CS}-gnutls ${SV} ${SV}-secure ${SV}-modbus \
		${HS} ${HS}-sqlite_browser #${CS}-gnade ${CS}-apq
PLIST_SUB=	ISC=include/${PORTNAME} LSC=lib/${PORTNAME} \
		SV=${SV} HS=${HS} SSM=gnat-sockets-connection_state_machine \
		SE=strings_edit PR=${CS}/parsers GN=${CS}/generic \
		PT=${CS}/persistent OD=${CS}-odbc OB=${CS}/object

do-build:
.for PROJECT in ${PROJECT_LIST}
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gprbuild -P${PROJECT})
.endfor

do-install:
	# Work around gprbuild's inability to handle separate package bodies
	# Create a dummy file, otherwise none of strings_edit gets installed
	${TOUCH} ${WRKSRC}/strings_edit-text_edit.o
.for PROJECT in ${PROJECT_LIST}
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gprinstall -p \
		--prefix=${DEST} \
		--project-subdir=${DEST}/lib/gnat \
		--sources-subdir=${DEST}/include/${PORTNAME}/${PROJECT} \
		--lib-subdir=${DEST}/lib/${PORTNAME}/${PROJECT} \
		${PROJECT}.gpr)
.endfor
	# end of workaround: remove dummy object file
	${RM} ${WRKSRC}/strings_edit-text_edit.o
	# Eject manifests, we don't use them
	${RM} -r ${DEST}/lib/gnat/manifests

.include <bsd.port.mk>
