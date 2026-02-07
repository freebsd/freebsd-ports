// Small example taken from https://howardhinnant.github.io/date/date.html.
// Only for testing installed header shortly.
#include <iostream>

#include "../include/date/date.h"

int main()
{
    using namespace std;
    using namespace date;
    for (auto m = 1; m <= 12; ++m)
    {
        auto meet = year_month_day{m/fri[1]/2015};
        cout << meet << '\n';
        meet = meet.year()/meet.month()/(meet.day()+weeks{2});
        cout << meet << '\n';
        meet = meet.year()/meet.month()/(meet.day()+weeks{2});
        if (meet.ok())
            cout << meet << '\n';
    }
}
