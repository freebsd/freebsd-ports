#!/bin/sh
#
# $FreeBSD$

IAM="`%%BASENAME%% "$0"`"

case "${IAM}" in
	openorb-idl_compiler)
		MAIN_CLASS=org.openorb.compiler.IdlCompiler
	;;
	openorb-naming_service)
		MAIN_CLASS=org.openorb.util.MapNamingContext
	;;
	*)
		echo "ERROR: command not supported" >&2
		exit 1
	;;
esac

JAVA_VERSION="1.3+" "%%LOCALBASE%%/bin/java" -classpath "%%CLASSPATH%%" "${MAIN_CLASS}" "$@"
