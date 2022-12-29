from korean_lunar_calendar import KoreanLunarCalendar

calendar = KoreanLunarCalendar()
# params : year(년), month(월), day(일)
calendar.setSolarDate(2017, 6, 24)
# Lunar Date (ISO Format)
print(calendar.LunarIsoFormat())
# Korean GapJa String
print(calendar.getGapJaString())
# Chinese GapJa String
print(calendar.getChineseGapJaString())

calendar = KoreanLunarCalendar()
# params : year(년), month(월), day(일), intercalation(윤달여부)
calendar.setLunarDate(1956, 1, 21, False)
# Solar Date (ISO Format)
print(calendar.SolarIsoFormat())
# Korean GapJa String
print(calendar.getGapJaString())
# Chinese GapJa String
print(calendar.getChineseGapJaString())

calendar = KoreanLunarCalendar()

# invald date
calendar.setLunarDate(99, 1, 1, False) # => return False
calendar.setSolarDate(2051, 1, 1) # => return False

# OK
calendar.setLunarDate(1000, 1, 1, False) # => return True
calendar.setSolarDate(2050, 12, 31) # => return True
